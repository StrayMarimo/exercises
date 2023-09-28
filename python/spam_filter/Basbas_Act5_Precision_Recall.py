import pandas as pd

# initialize counts of all measures to 0
measure = {'TP': 0, 'TN': 0, 'FP': 0, 'FN': 0}

# input/output files
labeledDF = pd.read_csv("LabeledTestData.csv")
resultDF = pd.read_csv("BasbasResultData.csv")
correctionDF = pd.DataFrame(columns=["value", "label", "result", "message"])

# iterate through each message in the labeled data
for index, row in labeledDF.iterrows():
    value = ""

    # determine if the prediction is true positive, true negative, false positive, or false negative
    if (row["label"] == resultDF.loc[index].at["label"]):
        value = "TP" if (row["label"] == "spam") else "TN"
    else:
        value = "FP" if (row["label"] == "spam") else "FN"
    
    # increment the count of the determined measure
    measure[value] += 1

    # add the measure, correct label, output label, and message to dataframe
    correctionDF.loc[len(correctionDF)] = [value, row["label"], resultDF.loc[index].at["label"], resultDF.loc[index].at["message"]]

# convert dataframe to output file
correctionDF.to_csv("BasbasPrecisionRecall.csv", index=False)

# print values
print(measure)
print("Precision: ", measure['TP'] / (measure['TP'] + measure['FP']))
print("Recall: ", measure['TP'] / (measure['TP'] + measure['FN']))