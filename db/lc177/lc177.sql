CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE X INT;
  SET X = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT IFNULL(
      (
          SELECT DISTINCT Salary
          FROM Employee
          ORDER BY Salary DESC
          LIMIT X, 1
      ), NULL) 
  );
END