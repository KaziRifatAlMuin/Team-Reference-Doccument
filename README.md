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

## Credits

- KUET_Anarosh
- KUET_Effervescent