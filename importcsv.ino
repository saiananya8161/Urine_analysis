import csv
import random

# Function to generate random pH values within the specified range
def generate_random_ph():
    return round(random.uniform(6.5, 7.5), 2)

# Function to generate random weight values within the specified range
def generate_random_weight():
    return round(random.uniform(1, 2), 2)

# Number of data points to generate
num_data_points = 100

# Generate data and write to CSV file
with open('data.csv', 'w', newline='') as csvfile:
    fieldnames = ['pH', 'Weight']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    for _ in range(num_data_points):
        ph_value = generate_random_ph()
        weight_value = generate_random_weight()
        writer.writerow({'pH': ph_value, 'Weight': weight_value})

print("CSV file generated successfully.")
