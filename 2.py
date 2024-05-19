class Element:
    def __init__(self, i, j, x):
        self.i = i
        self.j = j
        self.x = x

class Sparse:
    def __init__(self, m=0, n=0, num=0):
        self.m = m
        self.n = n
        self.num = num
        self.ele = []

    def create(self):
        self.m = int(input("Enter the dimension of the matrix: "))
        self.n = int(input())
        self.num = int(input("Number of non-zero elements: "))
        self.ele = []
        print("Enter the non-zero elements: ")
        for _ in range(self.num):
            i, j, x = map(int, input().split())
            self.ele.append(Element(i, j, x))

    def display(self):
        k = 0
        for i in range(self.m):
            for j in range(self.n):
                if k < self.num and i == self.ele[k].i and j == self.ele[k].j:
                    print(self.ele[k].x, end=" ")
                    k += 1
                else:
                    print("0", end=" ")
            print()

    def add(self, s2):
        if self.m != s2.m or self.n != s2.n:
            print("Addition cannot happen!!")
            return None
        
        s = Sparse(self.m, self.n)
        i = j = k = 0

        while i < self.num and j < s2.num:
            if self.ele[i].i < s2.ele[j].i or (self.ele[i].i == s2.ele[j].i and self.ele[i].j < s2.ele[j].j):
                s.ele.append(self.ele[i])
                i += 1
            elif self.ele[i].i > s2.ele[j].i or (self.ele[i].i == s2.ele[j].i and self.ele[i].j > s2.ele[j].j):
                s.ele.append(s2.ele[j])
                j += 1
            else:
                s.ele.append(Element(self.ele[i].i, self.ele[i].j, self.ele[i].x + s2.ele[j].x))
                i += 1
                j += 1
        
        while i < self.num:
            s.ele.append(self.ele[i])
            i += 1
        
        while j < s2.num:
            s.ele.append(s2.ele[j])
            j += 1
        
        s.num = len(s.ele)
        return s

def main():
    s1 = Sparse()
    s2 = Sparse()
    
    s1.create()
    s1.display()
    s2.create()
    s2.display()
    
    s3 = s1.add(s2)
    if s3:
        print("\n")
        s3.display()

if __name__ == "__main__":
    main()
