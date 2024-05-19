class Element {
    constructor(i, j, x) {
        this.i = i;
        this.j = j;
        this.x = x;
    }
}

class Sparse {
    constructor(m = 0, n = 0, num = 0) {
        this.m = m;
        this.n = n;
        this.num = num;
        this.ele = [];
    }

    create() {
        const readlineSync = require('readline-sync');
        this.m = parseInt(readlineSync.question("Enter the dimension of the matrix: "));
        this.n = parseInt(readlineSync.question());
        this.num = parseInt(readlineSync.question("Number of non-zero elements: "));
        console.log("Enter the non-zero elements: ");
        for (let i = 0; i < this.num; i++) {
            let [a, b, c] = readlineSync.question().split(' ').map(Number);
            this.ele.push(new Element(a, b, c));
        }
    }

    display() {
        let k = 0;
        for (let i = 0; i < this.m; i++) {
            for (let j = 0; j < this.n; j++) {
                if (k < this.num && i === this.ele[k].i && j === this.ele[k].j) {
                    process.stdout.write(this.ele[k++].x + " ");
                } else {
                    process.stdout.write("0 ");
                }
            }
            console.log();
        }
    }

    add(s2) {
        if (this.m !== s2.m || this.n !== s2.n) {
            console.log("Addition cannot happen!!");
            return null;
        }

        let s = new Sparse(this.m, this.n);
        let i = 0, j = 0, k = 0;

        while (i < this.num && j < s2.num) {
            if (this.ele[i].i < s2.ele[j].i || (this.ele[i].i === s2.ele[j].i && this.ele[i].j < s2.ele[j].j)) {
                s.ele.push(this.ele[i++]);
            } else if (this.ele[i].i > s2.ele[j].i || (this.ele[i].i === s2.ele[j].i && this.ele[i].j > s2.ele[j].j)) {
                s.ele.push(s2.ele[j++]);
            } else {
                s.ele.push(new Element(this.ele[i].i, this.ele[i].j, this.ele[i].x + s2.ele[j].x));
                i++;
                j++;
            }
        }

        while (i < this.num) {
            s.ele.push(this.ele[i++]);
        }

        while (j < s2.num) {
            s.ele.push(s2.ele[j++]);
        }

        s.num = s.ele.length;
        return s;
    }
}

function main() {
    const s1 = new Sparse();
    const s2 = new Sparse();

    s1.create();
    s1.display();
    s2.create();
    s2.display();

    const s3 = s1.add(s2);
    if (s3) {
        console.log();
        s3.display();
    }
}

main();
