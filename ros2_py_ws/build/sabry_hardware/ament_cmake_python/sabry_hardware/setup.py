from setuptools import find_packages
from setuptools import setup

setup(
    name='sabry_hardware',
    version='0.0.0',
    packages=find_packages(
        include=('sabry_hardware', 'sabry_hardware.*')),
)
