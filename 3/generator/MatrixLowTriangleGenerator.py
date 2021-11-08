from generator import MatrixGenerator
import matrix
import random


class MatrixLowTriangleGenerator(MatrixGenerator):
    def generate(self, size):
        new_matrix = matrix.MatrixLowTriangle(size)
        for i in range(size):
            for j in range(i + 1):
                new_matrix.put(i, j, random.uniform(-self.MAX_ABSOLUTE_MATRIX_VALUE, self.MAX_ABSOLUTE_MATRIX_VALUE))
        return new_matrix
