from reader.MatrixReader import MatrixReader
import matrix


class MatrixDiagonalReader(MatrixReader):

    def read(self, input_stream):
        matrix_size = int(input_stream.readline())
        new_matrix = matrix.MatrixDiagonal(matrix_size)
        values = list(map(float, input_stream.readline().split()))
        for i in range(matrix_size):
            new_matrix.put(i, i, values[i])
        return new_matrix
