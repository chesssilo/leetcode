import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(department, left_on='departmentId', right_on='id', suffixes=('_employee', '_department'))
    df = df.groupby('departmentId').apply(lambda x: x[x['salary'] == x['salary'].max()])
    df = df.reset_index(drop=True)
    df = df[['name_department', 'name_employee', 'salary']]
    df.columns = ['Department','Employee', 'Salary']
    return df