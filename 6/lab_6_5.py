import pickle
import random

from lab_6_1_2_3_4 import Time
if __name__ == '__main__':
    l=[]
    for i in range(10):
        l.append(Time(random.randint(0, 59), random.randint(0, 59), random.randint(0, 100)))
        l[-1].Out()
    t=Time(12,15,55)

    f = open('one_time.ser','wb')
    pickle.dump(t,f)
    f.close()

    f = open('many_time.ser', 'wb')
    for each in l:
        pickle.dump(each,f)
    f.close()

    l=[]
    print('\n'*5)
    f = open('many_time.ser', 'rb')
    try:
        while True:
            l.append(pickle.load(f))
    except EOFError as e:
        pass

    for each in l:
        each.Out()
