from setuptools import find_packages
from setuptools import setup

setup(
    name='turtlesim_catch_them_all',
    version='0.0.0',
    packages=find_packages(
        include=('turtlesim_catch_them_all', 'turtlesim_catch_them_all.*')),
)
