'''
1 4 7 12 15 1000
2 5 19 31 32 1001
3 8 24 33 35 1002
40 41 42 44 45 1003
99 100 103 106 128 1004
'''
def find_in(arr,target):
    row,col=0,len(arr[0])-1
    while row<len(arr) and col>=0:
        if(arr[row][col] >  target):col-=1
        elif arr[row][col] < target : row+=1
        else: return [row,col]
    return [-1,-1]
print(find_in([ [1, 4, 7, 12, 15, 1000], [2, 5, 19, 31, 32, 1001], [3, 8, 24, 33, 35, 1002], [40, 41, 42, 43, 45, 1003], [99, 100, 103, 106, 128, 1004], ],44))