import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    df = tweets.loc[tweets['content'].str.len() > 15 ]
    return df[['tweet_id']]