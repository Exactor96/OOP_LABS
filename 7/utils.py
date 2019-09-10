import sqlite3
con = sqlite3.connect('dictionary.sqlite3')

def getrandomword():
    cur=con.cursor()
    cur.execute("SELECT * FROM words ORDER BY RANDOM() LIMIT 1;")
    return str(cur.fetchone()[0]).upper()
