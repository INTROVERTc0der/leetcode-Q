# Write your MySQL query statement below
-- select 
-- min(id)as id,
-- email
-- from Person
-- group by email
-- order by id;

DELETE p2
FROM Person p1
JOIN Person p2 
ON p1.email = p2.email AND p1.id < p2.id;

