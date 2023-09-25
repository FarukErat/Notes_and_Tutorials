using System.ComponentModel.DataAnnotations;

namespace WorkoutProject.Dtos;

public class LoginRequestDto
{
    [Required]
    [MinLength(6), MaxLength(20)]
    public string Username { get; set; } = string.Empty;
    [Required, DataType(DataType.Password)]
    [MinLength(6), MaxLength(20)]
    public string Password { get; set; } = string.Empty;
}
