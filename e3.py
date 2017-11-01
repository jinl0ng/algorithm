result=[]
def split(result, n):
    def recursion(re, n, list):
        re.append(list[0:n+1])
        j = n
        L = list[j]
        for i in range(list[j-1], L//2+1):
            list[j] = i
            if len(list)<=j+1:
                list.append(L-i)
            else:
               list[j+1] = L-i
            recursion(re, j+1, list)
    list = []
    for i in range(1, n//2+1):
        if len(list)>1:
            list=[]
        list.append(i)
        list.append(n-i)
        recursion(result, 1, list)
split(result, 6)
