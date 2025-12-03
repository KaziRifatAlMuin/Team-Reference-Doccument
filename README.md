# KUET_Anarosh Team Reference Document

## Overview

This repository contains the KUET_Anarosh team's reference document, compiled from codes written by team members (Kazi Rifat Al Muin, Md. Arifur Rahman, Hassan Mohammad Naquibul Hoque) and most codes taken from KUET_Effervescent team members (Mehrab Hossain Opi, Arnob Sarker, Sharif Minhazul Islam).

The notebook includes implementations of various algorithms and data structures, along with mathematical notes and resources.

## Repository Structure

- `code/`: Contains algorithm implementations organized by category

- `math/`: LaTeX files for mathematical notes and formulas.

- `images/`: Supporting images and diagrams.

- `generate_pdf.py`: Python script to generate the PDF notebook.

- `notebook.tex`: LaTeX template for the notebook.

## Generating the Team Notebook

The Python script is a fork of the Stanford ICPC team's notebook generator. It hosts the team notebook with modifications: directories are sections, file names (without extensions) are subsections, and code comments support LaTeX math formatting.

### Generating PDF

**Requirements:**
- [Python 2/3](https://www.python.org/)
- [latexmk](https://www.ctan.org/pkg/latexmk/)

Run the script `generate_pdf.py` to generate the PDF file. The LaTeX template `notebook.tex` handles syntax highlighting for C/C++/Java/Python. Modify `notebook.tex` and `generate_pdf.py` to change color schemes or add languages.

## Using Linux Shell Commands

For users on Windows, you can use Windows Subsystem for Linux (WSL) to access a Linux terminal environment. Follow these steps to set up WSL and generate the notebook.

### Step 1: Install WSL on Windows

1. Open PowerShell or Command Prompt as Administrator.
2. Run the following command to enable WSL:
   ```
   wsl --install
   ```
3. Restart your computer if prompted.
4. After restart, WSL will install Ubuntu by default. Follow the on-screen instructions to set up a username and password.

### Step 2: Update WSL and Install Required Packages

1. Open the WSL terminal (search for "Ubuntu" in the Start menu).
2. Update the package list:
   ```
   sudo apt update
   ```
3. Upgrade the system:
   ```
   sudo apt upgrade -y
   ```

### Step 3: Install Python

1. Install Python 3 (Python 2 is deprecated, but the script supports both):
   ```
   sudo apt install python3 -y
   ```
2. Verify installation:
   ```
   python3 --version
   ```

### Step 4: Install LaTeX and latexmk

1. Install TeX Live (a comprehensive LaTeX distribution):
   ```
   sudo apt install texlive-full -y
   ```
   Note: This may take some time as it's a large package.
2. Alternatively, for a smaller installation, install the base TeX Live and latexmk:
   ```
   sudo apt install texlive-latex-base texlive-latex-extra latexmk -y
   ```
3. Verify latexmk installation:
   ```
   latexmk --version
   ```

### Step 5: Generate the PDF

1. Navigate to the repository directory in WSL:
   ```
   cd /mnt/c/Users/USER/OneDrive/My\ Codes/Codes/_Notebook
   ```
   Replace `USER` with your actual Windows username.
2. Run the Python script:
   ```
   python3 generate_pdf.py
   ```
3. The PDF should be generated in the current directory.

### Troubleshooting

**Issue: "Hash: not found" error**

The original script used a custom `Hash` command that may not be available on all systems. The script has been updated to use `md5sum` (standard on Linux) with a fallback to Python's hashlib. If you encounter this error with an older version of the script, update the `generate_pdf.py` file or ensure `md5sum` is installed:
```
sudo apt install coreutils -y
```

**Issue: Permission denied when running the script**

If you get a permission error, make the script executable:
```
chmod +x generate_pdf.py
```

**Issue: LaTeX compilation errors**

Ensure you have all required LaTeX packages. If using the minimal installation, you may need additional packages:
```
sudo apt install texlive-latex-extra texlive-fonts-recommended -y
```

## Credits

- KUET_Anarosh
- KUET_Effervescent