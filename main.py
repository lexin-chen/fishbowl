import nltk
from nltk.corpus import words
import random

# Download the 'words' corpus if not already downloaded
nltk.download('words')

# Get the list of words from the corpus
word_list = words.words()

# Generate random word
random_word = random.choice(word_list)

print("Random word:", random_word)