class Printer(object):

    def __init__(self, output_streams):
        self._output_streams = output_streams

    def print(self, matrix):
        for output_stream in self._output_streams:
            self._print_to(matrix, output_stream)

    def print_count(self, count):
        for output_stream in self._output_streams:
            print("Count in container ", count, file=output_stream)

    def _print_to(self, matrix, output_stream):
        output_stream.write(str(matrix.size))
        output_stream.write('\n')
        for i in range(matrix.size):
            for j in range(matrix.size):
                output_stream.write(str(matrix.get(i, j)))
                output_stream.write(' ')
            output_stream.write('\n')
