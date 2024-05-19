import java.util.Scanner;

class TermDocumentMatrix {
    private int[][] matrix;
    private int numTerm;
    private int numDoc;

    public TermDocumentMatrix(int numTerm, int numDoc) {
        this.numTerm = numTerm;
        this.numDoc = numDoc;
        matrix = new int[numTerm][numDoc];
    }

    public void updateTermFrequency(int term, int doc, int val) {
        if (term < numTerm && doc < numDoc) {
            matrix[term][doc] = val;
        } else {
            System.out.println("Please enter valid index of document or term");
        }
    }

    public int getTermFrequency(int term, int doc) {
        if (term < numTerm && doc < numDoc) {
            return matrix[term][doc];
        } else {
            System.out.println("Please enter valid index of document or term");
            return -1;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of terms: ");
        int numTerm = scanner.nextInt();
        System.out.print("Enter the number of documents: ");
        int numDoc = scanner.nextInt();

        TermDocumentMatrix matrix = new TermDocumentMatrix(numTerm, numDoc);

        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Update Term Frequency");
            System.out.println("2. Get Term Frequency");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter term index: ");
                    int term = scanner.nextInt();
                    System.out.print("Enter document index: ");
                    int doc = scanner.nextInt();
                    System.out.print("Enter value: ");
                    int val = scanner.nextInt();
                    matrix.updateTermFrequency(term, doc, val);
                    break;
                case 2:
                    System.out.print("Enter term index: ");
                    term = scanner.nextInt();
                    System.out.print("Enter document index: ");
                    doc = scanner.nextInt();
                    System.out.println("Term frequency: " + matrix.getTermFrequency(term, doc));
                    break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 0);

        scanner.close();
    }
}
