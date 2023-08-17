import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    st_subj_merge=pd.merge(students,subjects,how='cross')
    df=pd.merge(st_subj_merge,examinations,how='left',on=['student_id','subject_name'],indicator=True)
    df['_merge'] = df['_merge'].map({'left_only': 0, 'both': 1})
    df=df.groupby(['student_id','student_name','subject_name'])['_merge'].sum().reset_index(name='attended_exams')
    df=df.sort_values(by=['student_id','subject_name'])
    return df