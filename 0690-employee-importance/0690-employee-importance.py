class Solution:
    def getImportance(self, employees, id):
        # Map employee ID -> employee object
        employee_map = {}

        for employee in employees:
            employee_map[employee.id] = employee

        def dfs(employee_id):
            employee = employee_map[employee_id]

            total = employee.importance

            for subordinate_id in employee.subordinates:
                total += dfs(subordinate_id)

            return total

        return dfs(id)