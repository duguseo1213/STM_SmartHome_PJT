import mysql.connector
from datetime import datetime

def sql_data(stm_id, temp, hum, light):
    # MySQL 연결 설정
    config = {
        'host': '3.34.132.91',
        'port': '3306',
        'user': 'stm',
        'password': '1',
        'database': 'stm'
    }

    try:
        # MySQL에 연결
        conn = mysql.connector.connect(**config)

        now = datetime.now()
        formatted_now = now.strftime('%Y-%m-%d %H:%M:%S')

        # 커서 생성
        cursor = conn.cursor()

        # 데이터 삽입 쿼리 작성
        query = "INSERT INTO DHT11 (stm_id, temp, hum, date, light) VALUES (%s, %s, %s, %s, %s)"
        values = (stm_id, temp, hum, formatted_now, light);
        cursor.execute(query, values)

        # 변경사항 커밋
        conn.commit()
        print("데이터 삽입 성공")

    except mysql.connector.Error as err:
        print("MySQL 오류: {}".format(err))

    finally:
        # 연결 종료
        if 'conn' in locals():
            conn.close()