class TermDocumentMatrix:
    def __init__(self, num_term, num_doc):
        self.num_term = num_term
        self.num_doc = num_doc
        self.matrix = [[0 for _ in range(num_doc)] for _ in range(num_term)]

    def update_term_frequency(self, term, doc, val):
        if 0 <= term < self.num_term and 0 <= doc < self.num_doc:
            self.matrix[term][doc] = val
        else:
            print("Please enter valid index of document or term")

    def get_term_frequency(self, term, doc):
        if 0 <= term < self.num_term and 0 <= doc < self.num_doc:
            return self.matrix[term][doc]
        else:
            print("Please enter valid index of document or term")

def main():
    num_term = int(input("Enter the number of terms: "))
    num_doc = int(input("Enter the number of documents: "))
    matrix = TermDocumentMatrix(num_term, num_doc)

    while True:
        print("\nMenu:")
        print("1. Update Term Frequency")
        print("2. Get Term Frequency")
        print("0. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            term = int(input("Enter term index: "))
            doc = int(input("Enter document index: "))
            val = int(input("Enter value: "))
            matrix.update_term_frequency(term, doc, val)
        elif choice == 2:
            term = int(input("Enter term index: "))
            doc = int(input("Enter document index: "))
            print(f"Term frequency: {matrix.get_term_frequency(term, doc)}")
        elif choice == 0:
            print("Exiting...")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
