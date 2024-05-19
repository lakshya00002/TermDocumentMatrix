class TermDocumentMatrix {
    constructor(numTerm, numDoc) {
        this.numTerm = numTerm;
        this.numDoc = numDoc;
        this.matrix = Array.from({ length: numTerm }, () => Array(numDoc).fill(0));
    }

    updateTermFrequency(term, doc, val) {
        if (term < this.numTerm && doc < this.numDoc) {
            this.matrix[term][doc] = val;
        } else {
            console.log("Please enter valid index of document or term");
        }
    }

    getTermFrequency(term, doc) {
        if (term < this.numTerm && doc < this.numDoc) {
            return this.matrix[term][doc];
        } else {
            console.log("Please enter valid index of document or term");
            return -1;
        }
    }
}

function main() {
    const readline = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });

    readline.question("Enter the number of terms: ", numTerm => {
        readline.question("Enter the number of documents: ", numDoc => {
            const matrix = new TermDocumentMatrix(parseInt(numTerm), parseInt(numDoc));

            function menu() {
                console.log("\nMenu:");
                console.log("1. Update Term Frequency");
                console.log("2. Get Term Frequency");
                console.log("0. Exit");
                readline.question("Enter your choice: ", choice => {
                    switch (parseInt(choice)) {
                        case 1:
                            readline.question("Enter term index: ", term => {
                                readline.question("Enter document index: ", doc => {
                                    readline.question("Enter value: ", val => {
                                        matrix.updateTermFrequency(parseInt(term), parseInt(doc), parseInt(val));
                                        menu();
                                    });
                                });
                            });
                            break;
                        case 2:
                            readline.question("Enter term index: ", term => {
                                readline.question("Enter document index: ", doc => {
                                    console.log("Term frequency: " + matrix.getTermFrequency(parseInt(term), parseInt(doc)));
                                    menu();
                                });
                            });
                            break;
                        case 0:
                            console.log("Exiting...");
                            readline.close();
                            break;
                        default:
                            console.log("Invalid choice");
                            menu();
                    }
                });
            }

            menu();
        });
    });
}

main();
