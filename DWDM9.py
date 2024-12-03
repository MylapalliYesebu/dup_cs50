import numpy as np
import pandas as pd
from apyori import apriori

# Load data from CSV
store_data = pd.read_csv(r'C:\CodeHideout\Python_Playground\store_data.csv', header=None)

# Display the first few rows of the dataset
print(store_data.head())
print(store_data.shape)  # Displays the shape of the dataset (rows and columns)

# Preprocessing: Convert data into a list of lists for Apriori
records = []
for i in range(0, store_data.shape[0]):
    transaction = []
    for j in range(0, store_data.shape[1]):
        if pd.notna(store_data.values[i, j]):  # Ensure no NaN values are appended
            transaction.append(str(store_data.values[i, j]))
    if transaction:  # Only append non-empty transactions
        records.append(transaction)

print(type(records))  # Output: <class 'list'>

# Apriori Algorithm: Adjust the parameters for better results
association_rules = apriori(records, min_support=0.001, min_confidence=0.1, min_lift=1, min_length=2)
association_results = list(association_rules)

# Output: Number of relations derived
print("There are {} relations derived.".format(len(association_results)))

# Association Rules Derived: Print the base and add items for each rule
for i in range(0, len(association_results)):
    print(association_results[i][0])  # This prints the itemsets in each rule

# Output: Detailed Rules Generated
for item in association_results:
    pair = item[0]
    items = [x for x in pair]
    
    # Ensure that the itemset has at least 2 items
    if len(items) >= 2:
        print("Rule: " + items[0] + " -> " + items[1])
        print("Support: " + str(item[1]))
        print("Confidence: " + str(item[2][0][2]))
        print("Lift: " + str(item[2][0][3]))
        print("==========")

