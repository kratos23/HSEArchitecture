from generator import MatrixGenerator
import matrix
import random


class Matrix2DGenerator(MatrixGenerator):
    def generate(self, size):
        new_matrix = matrix.Matrix2D(size)
        for i in range(size):
            for j in range(size):
                new_matrix.put(i, j, random.uniform(-self.MAX_ABSOLUTE_MATRIX_VALUE, self.MAX_ABSOLUTE_MATRIX_VALUE))
