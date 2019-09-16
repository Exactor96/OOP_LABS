from tkinter import *
root=Tk()
LIVES=0
hang=PhotoImage(file=f'images\\{LIVES}.png')
hang=hang.subsample(2)
hang_label=Label(root,image=hang)
hang_label.pack()
def plus1():
    global LIVES,hang
    LIVES+=1

    hang=PhotoImage(file=f'images\\{LIVES}.png').subsample(2)

    print(f'sets images\\{LIVES}.png')
    hang_label.config(image=hang)
    #hang_label.after(1000, plus1)
    #hang_label['image']=hang_new
    #Label(root,image=hang)
    #hang_label.pack()


b = Button(root,text='+1',command=plus1)
b.pack()







root.mainloop()
