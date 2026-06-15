# The Codex - Mastering Python's Import Mysteries

## Introduction

The purpose of this project is to understand how Python imports work through a progressive construction of packages and modules.

The project focuses on:

* Python modules
* Python packages
* `import` statements
* `from ... import ...` statements
* Package interfaces through `__init__.py`
* Absolute imports
* Relative imports
* Nested packages
* Circular dependencies
* Techniques to avoid circular imports

All functions required by the subject are intentionally simple and only return strings. The goal is to learn Python's import system rather than implement complex logic.

---

# Project Structure

```text
.
├── elements.py
├── alchemy
│   ├── __init__.py
│   ├── elements.py
│   ├── potions.py
│   ├── transmutation
│   │   ├── __init__.py
│   │   └── recipes.py
│   └── grimoire
│       ├── __init__.py
│       ├── light_spellbook.py
│       ├── light_validator.py
│       ├── dark_spellbook.py
│       └── dark_validator.py
├── ft_alembic_0.py
├── ft_alembic_1.py
├── ft_alembic_2.py
├── ft_alembic_3.py
├── ft_alembic_4.py
├── ft_alembic_5.py
├── ft_distillation_0.py
├── ft_distillation_1.py
├── ft_transmutation_0.py
├── ft_transmutation_1.py
├── ft_transmutation_2.py
├── ft_kaboom_0.py
└── ft_kaboom_1.py
```

---

# Python Modules and Packages

## What is a Module?

A module is a single Python file.

Example:

```python
# elements.py

def create_fire() -> str:
    return "Fire element created"
```

The file itself is considered a module.

---

## What is a Package?

A package is a directory containing an `__init__.py` file.

Example:

```text
alchemy/
├── __init__.py
└── elements.py
```

The presence of `__init__.py` tells Python that the directory should be treated as a package.

---

## Role of `__init__.py`

`__init__.py` has two main purposes:

1. Mark a directory as a package.
2. Define the public interface of the package.

Example:

```python
from .elements import create_air
```

After this:

```python
import alchemy

alchemy.create_air()
```

works correctly.

Anything not exported inside `__init__.py` remains hidden from users importing the package.

---

# Part I - Alembic

## Objective

Learn different ways to import modules and package contents.

---

## ft_alembic_0

### Importing a Module

```python
import elements
```

Function access:

```python
elements.create_fire()
```

### Concept

The entire module is imported.

---

## ft_alembic_1

### Importing a Function

```python
from elements import create_water
```

Usage:

```python
create_water()
```

### Concept

Only the requested function is imported.

---

## Difference Between Import Styles

### Module Import

```python
import elements

elements.create_fire()
```

Advantages:

* Clear namespace
* Easier to identify function origins

---

### Direct Function Import

```python
from elements import create_fire

create_fire()
```

Advantages:

* Shorter syntax
* Convenient for frequently used functions

---

## ft_alembic_2

### Importing a Module from a Package

```python
import alchemy.elements
```

Usage:

```python
alchemy.elements.create_earth()
```

---

## ft_alembic_3

### Direct Import from a Package

```python
from alchemy.elements import create_air
```

Usage:

```python
create_air()
```

---

## ft_alembic_4

### Using Package Interface

```python
import alchemy
```

The package interface is controlled by:

```python
alchemy/__init__.py
```

Only exported functions are accessible.

Example:

```python
alchemy.create_air()
```

works.

Example:

```python
alchemy.create_earth()
```

raises:

```text
AttributeError
```

because `create_earth()` is intentionally hidden.

### Purpose

Demonstrate how a package can expose selected functionality while hiding implementation details.

---

## ft_alembic_5

### Importing from Package Interface

```python
from alchemy import create_air
```

Usage:

```python
create_air()
```

### Purpose

Show that functions exposed through `__init__.py` can be imported directly.

---

# Part II - Distillation

## Objective

Learn how modules can import and combine functionality from other modules.

---

## potions.py

Contains:

```python
healing_potion()
strength_potion()
```

Both functions rely on previously created elemental functions.

---

## healing_potion()

Uses:

```python
create_earth()
create_air()
```

to generate:

```text
Healing potion brewed with 'Earth element created'
and 'Air element created'
```

---

## strength_potion()

Uses:

```python
create_fire()
create_water()
```

to generate:

```text
Strength potion brewed with 'Fire element created'
and 'Water element created'
```

---

## Absolute Imports

An absolute import starts from the project root.

Example:

```python
from elements import create_fire
```

Advantages:

* Easy to read
* Explicit path

---

## Relative Imports

A relative import starts from the current package location.

Example:

```python
from .elements import create_air
```

The dot (`.`) means:

```text
Current package
```

Advantages:

* Package becomes easier to move
* Internal dependencies stay local

---

## Package Aliases

The subject requires:

```python
alchemy.heal()
```

even though the actual function is:

```python
healing_potion()
```

This is achieved through an alias inside:

```python
alchemy/__init__.py
```

Example concept:

```text
heal
  └──> healing_potion
```

---

# Part III - The Great Transmutation

## Objective

Understand the difference between absolute and relative imports.

---

## recipes.py

Contains:

```python
lead_to_gold()
```

which combines:

* Air element
* Strength potion
* Fire element

into a transmutation recipe.

---

## Absolute Import

Example:

```python
from elements import create_fire
```

Python starts searching from the project root.

---

## Relative Import

Example:

```python
from ..elements import create_air
```

Meaning:

```text
Go up one package level
and import elements.py
```

---

## Why Use Absolute Imports?

Advantages:

* Clear
* Easy to understand
* Recommended by PEP8 in many situations

Example:

```python
from alchemy.potions import strength_potion
```

---

## Why Use Relative Imports?

Advantages:

* Portable package structure
* Useful for internal package dependencies

Example:

```python
from ..potions import strength_potion
```

---

## Purpose of the Exercise

Demonstrate that both import styles can access the same functionality.

---

# Part IV - Avoid the Explosion

## Objective

Understand circular dependencies.

---

# What Is a Circular Import?

A circular import occurs when two modules depend on each other during initialization.

Example:

```text
spellbook.py
    imports validator.py

validator.py
    imports spellbook.py
```

Result:

```text
spellbook
    ↓
validator
    ↓
spellbook
    ↓
validator
```

Python cannot complete initialization and raises an error.

---

# Dark Magic

## Goal

Intentionally create a circular dependency.

---

## dark_spellbook.py

Imports:

```python
dark_validator
```

---

## dark_validator.py

Imports:

```python
dark_spellbook
```

---

## Result

Python raises:

```text
ImportError
```

or

```text
partially initialized module
```

This is the expected behaviour.

---

## ft_kaboom_1

Must fail intentionally.

The failure demonstrates the dangers of circular imports.

---

# Light Magic

## Goal

Avoid circular dependencies.

---

## Method 1 - Local Imports

Instead of importing at the top of the file:

```python
from validator import validate
```

perform the import inside a function:

```python
def record_spell():
    from validator import validate
```

The import only occurs when needed.

---

## Method 2 - Shared Module

Move shared information into a third module:

```text
constants.py
```

Both files import from it.

No circular dependency exists.

---

## Method 3 - Dependency Injection

Pass required data as function arguments rather than importing modules.

---

# Common Evaluation Questions

## What is a Python module?

A single Python file.

---

## What is a Python package?

A directory containing an `__init__.py` file.

---

## What is the purpose of `__init__.py`?

* Marks a package
* Defines its public interface
* Executes package initialization code

---

## Difference between `import` and `from ... import ...`

```python
import module

module.function()
```

versus

```python
from module import function

function()
```

---

## Difference between absolute and relative imports

Absolute:

```python
from alchemy.potions import strength_potion
```

Relative:

```python
from ..potions import strength_potion
```

---

## What is a circular import?

A situation where two modules import each other during initialization.

---

## Why does `ft_kaboom_1.py` fail?

Because `dark_spellbook.py` and `dark_validator.py` depend on each other, creating a circular import.

---

## Why does `ft_kaboom_0.py` work?

Because the circular dependency is avoided through a valid design strategy such as local imports or dependency separation.

---

# Conclusion

This project provides a complete overview of Python's import system, package organization, module visibility, import styles, and dependency management.

The most important lessons are:

* Understanding module imports.
* Building package interfaces using `__init__.py`.
* Choosing between absolute and relative imports.
* Recognizing and solving circular dependency issues.

These concepts are fundamental for writing scalable and maintainable Python applications.
