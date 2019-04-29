# Write your MySQL query statement below
SELECT T3.Name AS Department, T1.Name AS Employee, T1.Salary AS Salary
FROM Employee AS T1
JOIN Department AS T3
ON T1.DepartmentId = T3.Id
WHERE 3 >
(
    SELECT COUNT(DISTINCT Salary)
    FROM Employee AS T2
    WHERE T2.Salary > T1.Salary AND T1.DepartmentId = T2.DepartmentId
)