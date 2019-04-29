# Write your MySQL query statement below
SELECT T1.Name AS Department, T2.Name AS Employee, T2.Salary AS Salary 
FROM Department AS T1, Employee AS T2,
(
    SELECT DepartmentId, MAX(Salary) AS Salary
    FROM Employee
    GROUP BY DepartmentId
) AS T3
WHERE T1.Id = T2.DepartmentId AND T2.DepartmentId = T3.DepartmentId AND T2.Salary = T3.Salary