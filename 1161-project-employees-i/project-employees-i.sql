# Write your MySQL query statement below
select project_id, round(avg(e.experience_years),2) as average_year
from project p left join employee e
using(employee_id)
group by project_id