# KUET_NlogN - Team Reference Notebook

[![Python](https://img.shields.io/badge/python-3%2B-blue)](https://www.python.org/)
[![License](https://img.shields.io/badge/license-CC--BY--SA-lightgrey)](LICENSE)

A compact, LaTeX-based competitive programming reference compiled and maintained by the KUET_NlogN team.

This repository contains algorithms, data-structure snippets, math notes, and a generator to produce a printable PDF team notebook.

**Highlights:**
- Clear, categorized code snippets in `code/`
- LaTeX math notes in `math/`
- Notebook PDF generator: `generate_pdf.py`

**Quick Links:** `generate_pdf.py`, `notebook.tex`

---

## Overview

This repository contains the KUET_NlogN team’s competitive programming reference notebook.
It is compiled from implementations and notes written by:

- Kazi Rifat Al Muin
- Hassan Mohammad Naquibul Hoque
- Siyam Khan

The repository was initially cloned from the KUET_Effervescent team notebook and later extended and customized.

The notebook includes:
- Algorithm and data structure implementations
- Mathematical formulas and theory notes
- A LaTeX-formatted PDF suitable for programming contests

---

## Quick Start (Windows / WSL / Linux)

Recommended: use Windows with WSL (Ubuntu) or native Linux.

### Step A — (Windows) Install WSL and Ubuntu (PowerShell as Administrator)

```powershell
wsl --install
```

Reboot if prompted and complete the Ubuntu first-time setup.

### Quick switch
```powershell
wsl
wsl -d Ubuntu
exit
```

### Step B — Install system packages (Ubuntu / WSL / Linux)

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install python3 python3-pip latexmk texlive-latex-extra -y
```

Verify installations:

```bash
python3 --version
latexmk --version
```

### Optional TeX installations

Full TeX Live:

```bash
sudo apt install texlive-full -y
```

Smaller set (core + helpers):

```bash
sudo apt install texlive-latex-base texlive-latex-extra latexmk -y
```

---

## Generate the Notebook PDF

From the repository root directory, run:

```bash
python3 generate_pdf.py
```

The generated PDF will be created in the current directory (e.g., `notebook.pdf`).

---

## Requirements

- Python 3.6+
- `latexmk` and a TeX distribution (TeX Live recommended). For full coverage, `texlive-full`.

Windows users: enable WSL and run the above install commands inside your WSL distro.

---

## Repository Structure (short)

```
.
├── code/              # Algorithm implementations (by category)
├── math/              # LaTeX mathematical notes and proofs
├── images/            # Diagrams used in the notes
├── generate_pdf.py    # Script to compile the notebook PDF
├── notebook.tex       # Main LaTeX template and styling
└── README.md
```

Open `code/` to find categorized snippets (C/C++/Python/Java) suitable for contest use.

---

## Troubleshooting

### pdflatex error or "Nothing to do"

```bash
latexmk -C
python3 generate_pdf.py
```

Force rebuild:

```bash
latexmk -pdf -shell-escape -f notebook.tex
```

### Cannot write to `notebook.pdf`

```bash
rm notebook.pdf
python3 generate_pdf.py
```

On Windows PowerShell replace `rm` with `del` if needed.

### "Hash: not found" error

```bash
sudo apt install coreutils -y
```

### Permission denied

```bash
chmod +x generate_pdf.py
```

### Missing LaTeX packages

```bash
sudo apt install texlive-latex-extra texlive-fonts-recommended -y
```

---


- Add algorithm implementations under `code/` organized by category.
- Use clear filenames and include brief comments describing complexity and usage.
- Update `notebook.tex` if you need to change the PDF styling or supported languages.

---

## Credits

- KUET_NlogN (Kazi Rifat Al Muin, Hassan Mohammad Naquibul Hoque, Siyam Khan)
- KUET_Anarosh (Kazi Rifat Al Muin, Md Arifur Rahman, Hassan Mohammad Naquibul Hoque)
- KUET_Effervescent (Mehrab Hossain Opi, Arnob Sarker, Sharif Minhazul Islam)
