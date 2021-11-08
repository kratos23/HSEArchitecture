from reader.MatrixReader import MatrixReader
import matrix


class MatrixLowDiagonalReader(MatrixReader):

    def read(self, input_stream):
        matrix_size = int(input_stream.readline())
        new_matrix = matrix.MatrixLowTriangle(matrix_size)
        for i in range(matrix_size):
            values = list(map(float, input_stream.readline().split()))
            for j in range(i + 1):
                new_matrix.put(i, j, values[i])
        return new_matrix
