
def test1():
    while True:
        try:
            n1 = int(input('n1:'))
            n2 = int(input('n2:'))
            print(n1 / n2)
            return 1
        except Exception as err:
            print(err)
            return 0 
        finally:
            print('Done!')

def test2():
    aList = [1, 2, 3, 4, 5]
    i = 0
    while True:
        try:
            print(aList[i])
        except Exception as err:
            print(err)
            break
        else:
            i += 1
            

print(test1())
test2()
    
