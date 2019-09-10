from tkinter import *
from utils import *
import os
import re
from functools import partial


###constant block
r=0
c=0
LIVES=9

#####
root = Tk()
root.title('HANGMAN')
img_folder='images'
ALPHABET=['А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я']
root.geometry("800x600")
ALPHABET_Buttons=dict()
WORD=getrandomword()
WORD_STATE=['___' for each in WORD]
v=StringVar()
v.set(' '.join(WORD_STATE))
#print(' '.join(WORD_STATE))
hang=PhotoImage(file=f'images\\{LIVES}.png').subsample(3)
hang_label=Label(root,image=hang)
hang_label.pack()

def reloadState(guessed):
    global LIVES
    if guessed:
        v.set(' '.join(WORD_STATE))
    else:
        global hang_label,hang
        hang=PhotoImage(file=f'images\\{LIVES}.png').subsample(3)
        hang_label.config(image=hang)
        if LIVES <=0:
            v.set('GAME OVER')


def check_letter(letter):
    i=0
    t=ALPHABET_Buttons.get(letter)
    t.config(state='disabled')
    ALPHABET_Buttons.update({letter:t})
    global LIVES
    l=[]
    for each in list(WORD):
        if letter==each:
            l.append(i)
        i+=1
    if len(l)==0:
        LIVES-=1
        reloadState(False)
    else:
        for each in l:
            WORD_STATE[each]=letter
        reloadState(True)


def restart():
    global WORD,LIVES,WORD_STATE
    WORD=getrandomword()
    LIVES=9
    WORD_STATE=['___' for each in WORD]
    v.set(' '.join(WORD_STATE))
    reloadState(False)
    for each in ALPHABET_Buttons.items():
        each[1].config(state='normal')

frame1=Frame(root,bd=0)

for each in ALPHABET:
    ALPHABET_Buttons.update({each:Button(frame1,text=each,command=partial(check_letter, each))})


for i in ALPHABET_Buttons.items():
    i[1].grid(row=r, column=c, ipadx=10, ipady=6, padx=5, pady=5)
    if c % 11 == 0 and c is not 0:
        r+=1
        c=0
    else:
        c+=1
restart_button=Button(frame1,text='restart',command=restart)
restart_button.grid(row=r, column=c, ipadx=10, ipady=6, padx=5, pady=5)
frame1.pack()


Label(root,textvariable=v).pack()




root.mainloop()
