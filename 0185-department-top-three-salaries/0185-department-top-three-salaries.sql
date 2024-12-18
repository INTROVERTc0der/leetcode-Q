WITH t1 AS (
    SELECT 
        d.name AS Department,
        e.name AS name,
        e.salary AS salary
    FROM Employee e 
    JOIN Department d 
    ON e.departmentId = d.id
), t2 AS (
    SELECT 
        Department,
        name AS Employee,
        salary AS Salary,
        DENSE_RANK() OVER (PARTITION BY Department ORDER BY salary DESC) AS ranks
    FROM t1
)
SELECT
    Department,
    Employee,
    Salary 
FROM t2 
WHERE ranks <= 3;
