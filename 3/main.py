import printer
import container
import sys
import reader
import time


class ReaderCallback(reader.FileReaderCallback):

    def __init__(self, container):
        self.container = container

    def handle(self, matrix):
        self.container.add(matrix)


def main():
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    start_time = time.time()

    matrix_container = container.Container()
    file_reader = reader.FileReader(ReaderCallback(matrix_container))
    output_file_stream = open(output_file, 'w')
    matrix_printer = printer.Printer([sys.stdout, output_file_stream])

    file_reader.read(input_file)
    for i in range(matrix_container.get_size()):
        matrix_printer.print(matrix_container.data[i])
    matrix_printer.print_count(matrix_container.get_size())
    matrix_container.sort()
    for i in range(matrix_container.get_size()):
        matrix_printer.print(matrix_container.data[i])

    output_file_stream.close()
    end_time = time.time()
    print("Elapsed time ", end_time - start_time)


main()
