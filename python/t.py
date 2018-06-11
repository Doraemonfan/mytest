#! /usr/bin/env python3

from tkinter import *

class Application(Frame):
	def __int__(self, master=None):
		Frame.__init__(self, master)
		self.pack()
		slef.createWidgets()

	def createwidgets(self):
		self.helloLabel = Label(self, text='hello,world')
		self.helloLabel.pack()
		self.quitButton = Button(self, text='quit', command = self.quit)
		self.quitButton.pack()


app = Application()
app.master.title('zlimbo')
app.mainloop()
