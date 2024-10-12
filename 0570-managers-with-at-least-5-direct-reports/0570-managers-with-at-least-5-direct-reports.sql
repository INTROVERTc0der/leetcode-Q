# Write your MySQL query statement below
-- select name from Employee where id in (select managerId from Employee group by managerId having count(managerId)>=5);

-- SELECT name 
-- FROM Employee 
-- WHERE id IN (
--     SELECT managerId 
--     FROM Employee 
--     GROUP BY managerId 
--     HAVING COUNT(*) >= 5
-- );


with t1 as (
    select 
    e2.managerId,
    e1.name
    from Employee e2 join Employee e1
    on e1.id=e2.managerId
)
    select 
    name 
    from t1 
    group by managerId
    having count(managerId)>=5;
