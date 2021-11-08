import matrix.Matrix


class Container:

    def __init__(self):
        self.data = []

    def add(self, new_matrix):
        self.data.append(new_matrix)

    def get(self, index):
        return self.data[index]

    def get_size(self):
        return len(self.data)

    def set(self, index, new_matrix):
        self.data[index] = new_matrix

    def sort(self):
        for i in range(self.get_size()):
            for j in range(i + 1, self.get_size()):
                if self._get_average(self.data[i]) > self._get_average(self.data[j]) :
                    self.data[i], self.data[j] = self.data[j], self.data[i]

    def _get_average(self, cur_matrix):
        matrix_sum = 0
        for i in range(cur_matrix.size):
            for j in range(cur_matrix.size):
                matrix_sum += cur_matrix.get(i, j)
        return matrix_sum / (cur_matrix.size * cur_matrix.size)
