import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout,QPushButton, QMainWindow,QCalendarWidget
from PyQt5.QtCore import Qt
from PyQt5.QtCore import QDate
from PyQt5.QtCore import QTime
from PyQt5.QtGui import *
from PyQt5.QtCore import QTimer



class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.date = QDate.currentDate()
        self.label_time=QLabel()
        self.label_temp=QLabel()
        self.label_humi=QLabel()
        self.btn_c=QPushButton()
        self.background_label = QLabel(self)
        self.background_label.setGeometry(0, 0, 800, 480)
        self.background_label.setStyleSheet("background-image: url('background.jpg');")
        self.initUI()

    def initUI(self):
        temp= 12345
        humi=12345
        self.setWindowTitle('My First Application')
        self.move(300, 300)
        self.resize(800, 480)
        
        now = QDate.currentDate()
        time = QTime.currentTime()

        
        self.label_temp = QLabel(str(temp)+"C", self)
        self.label_temp.setStyleSheet("color:white;"
                                      "font-weight:bold;")
        self.label_temp.move(100, 100)
        font1 = self.label_temp.font()
        font1.setPointSize(60)
        self.label_temp.setFont(font1)
        
        self.label_humi = QLabel(str(humi)+"%", self)
        self.label_humi.setStyleSheet("color:white;"
                                      "font-weight:bold;")

        self.label_humi.move(100, 250)
        font2 = self.label_humi.font()
        font2.setPointSize(60)
        self.label_humi.setFont(font2)
        
        self.label_time = QLabel(time.toString(), self)
        self.label_time.setStyleSheet("color:white;"
                                       "font-weight:bold;")

        self.label_time.move(450, 50)
        font3 = self.label_time.font()
        font3.setPointSize(40)
        self.label_time.setFont(font3)
        
        cal = QCalendarWidget(self)
        cal.setGridVisible(True)
        cal.setGeometry(450, 130, 250,210 )

        
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_label)
        self.timer.start(1000) 
      
        self.show()
    def update_label(self):
        File = open("test.txt", "r")
        text = File.read()
        print(text)
        temp, humi = text.split(' ')
        now = QDate.currentDate()
        time = QTime.currentTime()
        
        self.label_time.setText(time.toString())    
        self.label_temp.setText(str(temp)+'C')   
        self.label_humi.setText(str(humi)+'%')   

        
    def curtain_sig(self):
        print("Send")


if __name__ == '__main__':
   app = QApplication(sys.argv)
   ex = MyApp()
   sys.exit(app.exec_())

