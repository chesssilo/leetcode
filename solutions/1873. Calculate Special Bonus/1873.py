import pandas as pd
import numpy as np

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = np.where( (employees['employee_id'] % 2 == 0) | (employees['name'].str.match('M')),  0, employees['salary'])
    df = employees[['employee_id','bonus']].sort_values(by=['employee_id'])
    return df