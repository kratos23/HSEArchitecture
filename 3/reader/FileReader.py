from .Matrix2DReader import *
from .MatrixDiagonalReader import *
from .MatrixLowDiagonalReader import *
import generator
import random
import abc


class FileReaderCallback(object):
    @abc.abstractmethod
    def handle(self, matrix):
        "Handles read matrix"
        return


class FileReader(object):
    RAW_INPUT_TYPE = "raw"
    RANDOM_INPUT_TYPE = "random"
    MAX_RANDOM_MATRTIX_SIZE = 10

    DIAGONAL_MATRIX_TYPE = "diagonal"
    LOW_TRIANGLE_MATRIX_TYPE = "low_triangle"
    TWO_DIMENSIONS_MATRIX_TYPE = "2d"

    _matrixReaders = {}

    def __init__(self, reader_callback):
        self._matrixReaders[self.DIAGONAL_MATRIX_TYPE] = MatrixDiagonalReader()
        self._matrixReaders[self.TWO_DIMENSIONS_MATRIX_TYPE] = Matrix2DReader()
        self._matrixReaders[self.LOW_TRIANGLE_MATRIX_TYPE] = MatrixLowDiagonalReader()
        self._reader_callback = reader_callback

    def read(self, filename):
        input_stream = open(filename, 'r')
        input_type = input_stream.readline().strip()
        if input_type == self.RAW_INPUT_TYPE:
            self._read_raw(input_stream)
        elif input_type == self.RANDOM_INPUT_TYPE:
            self._read_random(input_stream)
        input_stream.close()

    def _read_random(self, input_stream):
        random_key = int(input_stream.readline())
        random.seed(random_key)

        input_stream.readline()

        count = int(input_stream.readline())
        generators = [
            generator.Matrix2DGenerator(),
            generator.MatrixLowTriangleGenerator(),
            generator.MatrixDiagonalGenerator()
        ]
        for i in range(count):
            cur_generator = generators[random.randrange(0, len(generators))]
            given_matrix = cur_generator.generate(random.randrange(1, self.MAX_RANDOM_MATRTIX_SIZE + 1))
            self._reader_callback.handle(given_matrix)

    def _read_raw(self, input_stream):
        while True:
            matrix_type = input_stream.readline().strip()
            if matrix_type == "":
                break
            else:
                given_matrix = self._matrixReaders[matrix_type].read(input_stream)
                self._reader_callback.handle(given_matrix)

        pass
