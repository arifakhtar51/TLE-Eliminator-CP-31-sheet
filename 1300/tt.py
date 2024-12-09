from PyPDF2 import PdfReader

# Path to the uploaded PDF
pdf_path = "C:\Users\arifa\Downloads\icpc_.pdf"

# Reading the PDF
reader = PdfReader(pdf_path)

# Extracting all text from the PDF
all_text = ""
for page in reader.pages:
    all_text += page.extract_text()

# Finding all unique team IDs (assumed to be numbers starting the line, 7 digits)
import re
team_ids = re.findall(r"\b\d{7}\b", all_text)
unique_team_ids = set(team_ids)

# Count of unique team IDs
total_teams = len(unique_team_ids)
total_teams
