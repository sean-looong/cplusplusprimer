#!/bin/bash

echo "add:" && ./add < data/add 
echo "add_item:" && ./add_item < data/add_item
echo "add_item2:" && ./add_item2 < data/add_item
echo "avg_price:" && ./avg_price < data/book_sales
echo "item_io:" && ./item_io < data/book_sales 
echo "occurs:" && ./occurs < data/occurs
echo "mysum:" && ./mysum < data/mysum

