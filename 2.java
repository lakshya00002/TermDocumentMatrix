import java.util.Scanner;

class Element {
    int i, j, x;

    Element(int i, int j, int x) {
        this.i = i;
        this.j = j;
        this.x = x;
    }
}

class Sparse {
    int m, n, num;
    Element[] ele;

    Sparse() {}

    Sparse(int m, int n, int num) {
        this.m = m;
        this.n = n;
        this.num = num;
        ele = new Element[num];
    }

    void create() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the dimension of the matrix: ");
        m = scanner.nextInt();
        n = scanner.nextInt();
        System.out.print("Number of non-zero elements: ");
        num = scanner.nextInt();
        ele = new Element[num];
        System.out.println("Enter the non-zero elements: ");
        for (int i = 0; i < num; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            ele[i] = new Element(a, b, c);
        }
    }

    void display() {
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (k < num && i == ele[k].i && j == ele[k].j) {
                    System.out.print(ele[k].x + " ");
                    k++;
                } else {
                    System.out.print("0 ");
                }
            }
            System.out.println();
        }
    }

    Sparse add(Sparse s2) {
        if (m != s2.m || n != s2.n) {
            System.out.println("Addition cannot happen!!");
            return null;
        }

        Sparse s = new Sparse(m, n, num + s2.num);
        int i = 0, j = 0, k = 0;

        while (i < num && j < s2.num) {
            if (ele[i].i < s2.ele[j].i || (ele[i].i == s2.ele[j].i && ele[i].j < s2.ele[j].j)) {
                s.ele[k++] = ele[i++];
            } else if (ele[i].i > s2.ele[j].i || (ele[i].i == s2.ele[j].i && ele[i].j > s2.ele[j].j)) {
                s.ele[k++] = s2.ele[j++];
            } else {
                s.ele[k] = new Element(ele[i].i, ele[i].j, ele[i].x + s2.ele[j].x);
                i++;
                j++;
                k++;
            }
        }

        while (i < num) {
            s.ele[k++] = ele[i++];
        }

        while (j < s2.num) {
            s.ele[k++] = s2.ele[j++];
        }

        s.num = k;
        return s;
    }
}

public class Main {
    public static void main(String[] args) {
        Sparse s1 = new Sparse();
        Sparse s2 = new Sparse();

        s1.create();
        s1.display();
        s2.create();
        s2.display();

        Sparse s3 = s1.add(s2);
        if (s3 != null) {
            System.out.println();
            s3.display();
        }
    }
}
