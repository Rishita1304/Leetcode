# Write your MySQL query statement below
select s.student_id, s.student_name, sub.subject_name, count(e.subject_name) as attended_exams
from students s
cross join subjects sub
left join examinations e
using(student_id, subject_name)
group by s.student_id, s.student_name, sub.subject_name
order by s.student_id,sub.subject_name