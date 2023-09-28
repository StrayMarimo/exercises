import pandas as pd
import re

LAPLACE_SMOOTHING = 0.1

# function to clean the message and return a list of words
# a word is a string of characters that are all letters
# and has a whitespace before and either a comma, period or space after it
def string_splitter(message):
    message = message.lower();
    return re.findall(r'((?<= )[A-Za-z]+(?=[, .]))', message)

def get_probability(count, is_spam):
    return (count + LAPLACE_SMOOTHING) / ((n_spam if is_spam else n_ham) + LAPLACE_SMOOTHING * total_words)

# function to predict if a message is spam or ham
def predict(message):
    # clean the message and split it into a list of words
    message = string_splitter(message)

    # save the probability of the message being spam or ham to a local variable
    # so that the global variables are not affected
    prod_spam = p_spam
    prod_ham = p_ham
    
    # for each word in the message, multiply the probability of the word 
    # being spam or ham
    for word in message:

        # if word exists in the training data, 
        # multiply its probability of being spam and/or ham
        # that was saved in the dictionary
        if word in prob_spam_words:
            prod_spam *= prob_spam_words[word]
            
        if word in prob_ham_words:
            prod_ham *= prob_ham_words[word]

    # return prediction based on which probability is greater
    return 'ham' if prod_ham > prod_spam else 'spam'

# input/output files
training_data = pd.read_csv('TrainingData.csv')
test_data = pd.read_csv('TestData.csv');
result_data = pd.DataFrame(columns=['label', 'message'])

# change the column for message in training data to list_message
# since its data will be changed to a list of words
column_mapping = {'label': 'label', 'message': 'list_message'}
training_data = training_data.rename(columns=column_mapping)
words = []

# iterate through each message in the training data
for _, row in training_data.iterrows():
    # call the string_splitter function to clean the message 
    splitted = string_splitter(row['list_message'])
    words.extend(splitted); # add the words to the list of words
    row['list_message'] = splitted # change the message to a list of words

# remove duplicate words
words = list(set(words))

# create a dictionary for each unique word and initialize each key to 0
# will be used for counting the occurence of each word in each message
words_rate = {unique_word: [0] * len(training_data['list_message']) for unique_word in words}

# create a dictionary for each unique word and initialize each key to 0
# will be used for probability of each word being spam or ham
prob_ham_words = {unique_words: 0 for unique_words in words}
prob_spam_words = {unique_words: 0 for unique_words in words}

# counts the occurence of each word in each message
for index, msg in enumerate(training_data['list_message']):
    for word in msg:
        words_rate[word][index] += 1

# combine columns of training data and the words_rate dictionary 
# that is converted to a dataframe
train_word = pd.concat([training_data, pd.DataFrame(words_rate)], axis = 1)

# remove rows with null values in label column
train_word = train_word[pd.notnull(train_word['label'])]

# Get the spam and ham messages
spam_messages = train_word[train_word['label'] == 'spam']
ham_messages = train_word[train_word['label'] == 'ham']

# P(spam | ham) = number of spam|ham messages / total number of messages
p_spam = len(spam_messages) / len(train_word)
p_ham = len(ham_messages) / len(train_word)

# calculates the sum of the number of words in each of the spam and ham messages
n_spam = spam_messages['list_message'].apply(len).sum()
n_ham = ham_messages['list_message'].apply(len).sum()

# get total number of unique words
total_words = len(words)

# calculate the probability of each unique word being spam or ham
for word in words:
    prob_spam_words[word] = get_probability(spam_messages[word].sum(), True)
    prob_ham_words[word] = get_probability(ham_messages[word].sum(), False)

# predict the label of each message in the test data
for index, row in test_data.iterrows():
    result_data.loc[index] = [predict(row['message']), row['message']]

# save the result to a csv file
result_data.to_csv('BasbasResultData.csv', index=False)

