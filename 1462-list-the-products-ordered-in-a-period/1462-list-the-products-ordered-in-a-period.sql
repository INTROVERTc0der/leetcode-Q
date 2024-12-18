# Write your MySQL query statement below
with t1 as(
    select product_id,
    sum(unit) as totalUnits
    from Orders
    where order_date between "2020-02-01" and "2020-02-29"
    group by product_id
    having sum(unit)>=100
)
select p.product_name,
t.totalUnits as unit
from Products p join t1 t 
on p.product_id=t.product_id;
