from generator import MatrixGenerator
import matrix
import random


class MatrixDiagonalGenerator(MatrixGenerator):
    def generate(self, size):
        new_matrix = matrix.MatrixDiagonal(size)
        for i in range(size):
            new_matrix.put(i, i, random.uniform(-self.MAX_ABSOLUTE_MATRIX_VALUE, self.MAX_ABSOLUTE_MATRIX_VALUE))
        return new_matrix