from reader.MatrixReader import MatrixReader
import matrix


class Matrix2DReader(MatrixReader):

    def read(self, input_stream):
        matrix_size = int(input_stream.readline())
        new_matrix = matrix.Matrix2D(matrix_size)
        for i in range(matrix_size):
            values = list(map(float, input_stream.readline().split()))
            for j in range(matrix_size):
                new_matrix.put(i, j, values[j])
        return new_matrix