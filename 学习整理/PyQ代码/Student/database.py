import sqlite3
class DataBase():
    # ******************    连接数据库       *******************#
    def connData(self):
        try:
            self.conn = sqlite3.connect("student.db")
            return True
        except Exception as e:
            return False

    # ******************    查询数据库数据       *******************#
    def selectData(self):
        try:
            if(self.connData()):
                self.cursor = self.conn.cursor()
                self.cursor.execute("select * from studentInfo")
                self.data = self.cursor.fetchall()
                self.conn.commit()
                self.conn.close()
            return True
        except Exception as e:
            return False
        finally:
            self.conn.close()

