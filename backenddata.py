import sqlite3
import pandas as pd

def get_data():
    conn = sqlite3.connect('data.db')
    df = pd.read_sql_query("SELECT