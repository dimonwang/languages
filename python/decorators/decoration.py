#!/bin/python

def deco(fn):
    def dodeco(*args):
        print("do decoration")
        fn(*args)
    return dodeco

@deco
def susu(a,b):
    print(a*b)

if __name__ == "__main__":
    susu(2,5)
